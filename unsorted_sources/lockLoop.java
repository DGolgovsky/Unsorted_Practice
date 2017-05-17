public class LockFactory {
    private static LockFactory instance;
    private int numberOfLocks = 5; /* по умолчанию */
    private LockNode[] locks;
    
    /* Отображаем процесс (владельца) в порядок,
     * в котором владелец требовал блокировку */
    
    private Hashtable<Integer, LinkedList<LockNode>> lockOrder;
    
    private LockFactory(int count) { /* ... */ }
    public static LockFactory getInstance() { return instance; }
    
    public static synchronized LockFactory initialize(int count) {
        if (instance == null)
            instance = new LockFactory(count); 
        return instance;
    }
    
    public boolean hasCycle(Hashtable<Integer, Boolean> touchedNodes, int[] resourcesInOrder) {
        /* проверяем на наличие петли */
        for (int resource : resourcesInOrder) {
            if (touchedNodes.get(resource) == false) {
                LockNode n = locks[resource];
                if (n.hasCycle(touchedNodes)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    /* Чтобы предотвратить мертвую блокировку, заставляем процессы
    *    объявлять, что они хотят заблокировать. Проверяем,
    *    что запрашиваемый порядок не вызовет мертвую блокировку
    *    (петлю в направленном графе) */
    public boolean declare(int ownerId, int[] resourcesInOrder) {
        Hashtable<Integer, Boolean> touchedNodes = new Hashtable<Integer, Boolean>();
        /* добавляем узлы в граф */
        int index = 1;
        touchedNodes.put(resourcesInOrder[0], false);
        for (index = 1; index < resourcesInOrder.length; index++) {
            LockNode prev = locks[resourcesInOrder[index - 1]];
            LockNode curr = locks[resourcesInOrder[index]];
            prev.joinTo(curr);
            touchedNodes.put(resourcesInOrder[index], false);
        }
        /* если получена петля, уничтожаем этот список ресурсов
         * и возвращаем false */
        if (hasCycle(touchedNodes, resourcesInOrder)) {
            for (int j = 1; j < resourcesInOrder.length; j++) {
                LockNode p = locks[resourcesInOrder[j - 1]];
                LockNode c = locks[resourcesInOrder[j]];
                p.remove(c);
            }
            return false;
        }
        /* Петля не найдена. Сохраняем порядок, который был объявлен,
         *    так как мы можем проверить, что процесс действительно вызывает
         *    блокировку в нужном порядке */
        LinkedList<LockNode> list = new LinkedList<LockNode>();
        for (int i = 0; i < resourcesInOrder.length; i++) {
            LockNode resource = locks[resourcesInOrder[i]];
            list.add(resource);
        }
        lockOrder.put(ownerId, list);
        
        return true;
    }
    /* Получаем блокировку, проверяем сначала, что процесс
     * действительно запрашивает блокировку в объявленном порядке*/
    public Lock getLock(int ownerld, int resourceID) {
        LinkedList<LockNode> list = lockOrder.get(ownerId);
        if (list == null) return null;
        
        LockNode head = list.getFirst();
        if (head.getId() == resourceID) {
            list.removeFirst();
            return head.getLock();
        }
        return null;
    }
}

public class LockNode {
    public enum VisitState { FRESH, VISITING, VISITED };
    
    private ArrayList<LockNode> children;
    private int lockId;
    private Lock lock;
    private int maxLocks;
    
    public LockNode(int id, int max) { /* ... */ }
    
    /* Присоединяем "this" в "node", проверяем, что мы не создадим этим
    * петлю (цикл) */
    public void joinTo(LockNode node) { children.add(node); }
    public void remove(LockNode node) { children.remove(node); }
    
    /* Проверяем на наличие цикла с помощью поиска в глубину */ 
    public boolean hasCycle(Hashtable<Integer, Boolean> touchedNodes) {
        VisitState[] visited = new VisitState[maxLocks];
        for (int i = 0; i < maxLocks; i++) {
            visited[i] = VisitState.FRESH;
        }
        return hasCycle(visited, touchedNodes);
    }
    
    private boolean hasCycle(VisitState[] visited,
    Hashtable<Integer, Boolean> touchedNodes) {
        if (touchedNodes.containsKey(lockId)) {
            touchedNodes.put(lockId, true);
        }
        if (visited[lockId] == VisitState.VISITING) {
            /* Мы циклично возвращаемся к этому узлу, следовательно, 
             * мы знаем, что здесь есть цикл (петля) */
            return true;
        } else if (visited[lockId] == VisitState.FRESH) {
            visited[lockId] = VisitState.VISITING;
            for (LockNode n : children) {
                if (n.hasCycle(visited, touchedNodes)) {
                    return true;
                }
            }
            visited[lockId] = VisitState.VISITED;
        }
        return false;
    }
 
    public Lock getLock() {
        if (lock == null) lock = new ReentrantLock();
        return lock;
    }
    
    public int getId() { return lockId; }
}
