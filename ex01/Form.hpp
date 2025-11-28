

class Form {
    private:
        std::string const _name;
        bool _signed;
        const int reqGradeToSign;
        const int reqGradeToExec;

    public:
        std::string getName() const;
        bool    isSigned();
        const int     requiredGradeToSign();
        const int     requiredGradeToExecute()


}

std::ostream& operator<<(std::ostream &os, Form &other);