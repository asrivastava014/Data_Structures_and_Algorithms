#ifndef USER_H
#define USER_H

class User
{
    private:
        static int user_count;
        std::string first_name;
        std::string last_name;
        std::string status;
    
    public:
        static int get_user_count();
        std::string get_status();  //Getter function 
        void set_status(std::string status); //Setter function
       
        User();     
        User(std::string first_name, std::string last_name, std::string status);
        ~User();       
        friend std::ostream& operator << (std::ostream& output, const User user);
        friend std::istream& operator >> (std::istream& input, User &user);
        friend void show_status(User user);

};


#endif

