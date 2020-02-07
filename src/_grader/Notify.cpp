class INotifier {
public:
//	INotifier(){};
	virtual void Notify(const string& message) const = 0;
};

class SmsNotifier : public INotifier {
public:
	SmsNotifier(const string& phone_no) : phone_no_(phone_no) {}
	void Notify(const string& message) const override {
		SendSms(phone_no_, message);
	}
private:
	const string phone_no_;
};

class EmailNotifier : public INotifier {
public:
	EmailNotifier(const string& email) : email_(email){}
	void Notify(const string& message) const override {
		SendEmail(email_, message);
	}
private:
	const string email_;
};