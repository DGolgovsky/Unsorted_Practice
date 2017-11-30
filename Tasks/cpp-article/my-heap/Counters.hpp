class Counters
{
public:
    Counters() :
#ifndef NDEBUG // Enabled in debug builds
        m_debugAllCounters(0),
#endif
        m_counter1(0),
        m_counter2(0)
        { }

#ifndef NDEBUG // Enabled in debug build
#endif
    void inc1() {
#ifndef NDEBUG // Enabled in debug build
        ++m_debugAllCounters;
#endif
        ++m_counter1;
    }

    void inc2() {
#ifndef NDEBUG // Enabled in debug build
        ++m_debugAllCounters;
#endif
        ++m_counter2;
    }

#ifndef NDEBUG // Enabled in debug build
    int getDebugAllCounters() {
        return m_debugAllCounters;
    }
#endif
    int get1() const { return m_counter1; }
    int get2() const { return m_counter2; }

private:
#ifndef NDEBUG // Enabled in debug builds
    int m_debugAllCounters;
#endif
    int m_counter1;
    int m_counter2;
};

