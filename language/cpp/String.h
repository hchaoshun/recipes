class String {
public:
    String();
    String(char *data);
    String(const String &str);
    String(String &&str);
    String &operator=(const String &str);
    String &operator=(String str);
    String &operator=(String &&str);
    size_t size() const;
    void swap(String &str);
    ~String();
    
private:
    char *data_;
};
