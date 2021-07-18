namespace dtl {
    template<typename T>
    class optional {
        union {
            T held;
        };
        bool have_t;
        
        public:
    };
}