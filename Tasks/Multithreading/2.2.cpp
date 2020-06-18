/* ------ COPY BY ARG --------- */
void f(int i, std::string const &s);

void oops(int some_param) {
	char buffer[1024];
	sprintf(buffer, "%i", some_param);
	std::thread t(f, 3, buffer); // Pointer to local var `buffer`
	t.detach();
}

void not_oops(int some_param) {
	char buffer[1024];
	sprintf(buffer, "%i", some_param);
	std::thread t(f, 3, std::string(buffer));
	t.detach();
}

/* ------ COPY BY REF --------- */
void update_data_for_widget(widget_id w, widget_data &data);

void oops_again(widget_id w) {
	widget_data data;
	std::thread t(update_data_for_widget, w, data); // copy of local `data`
	std::thread t(update_data_for_widget, w, std::ref(data)); // reference to `data`
	display_status();
	t.join();
	process_widget_data(data);
}

/* ------ CLASS->REF ------- */
class X
{
public:
	void do_lengthy_work();
};

X my_x;
std::thread t(&X::do_lengthy_work, &my_x);

/* ------- MOVE ------- */
void process_big_object(std::unique_ptr < big_object > );

std::unique_ptr <big_object> p(new big_object);
p->prepare_data(42);
std::thread t(process_big_object, std::move(p));

