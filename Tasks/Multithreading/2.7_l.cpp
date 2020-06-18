void do_work(unsigned id);

void f() {
	std::vector <std::thread> threads;
	for (unsigned i = 0; i < 20; ++i) {
		// Запуск потоков
		threads.push_back(std::thread(do_work, i));
	}
	// Поочередный вызов join() для каждого потока
	std::for_each(threads.begin(), threads.end(),
				  std::mem_fn(&std::thread::join));
}

