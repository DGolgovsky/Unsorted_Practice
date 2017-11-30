void edit_document(std::string const& filename)
{
    open_document_and_display_gui(filename);
    while (!done_editing()) {
        user_command cmd = get_user_input();
        if (cmd.type == open_new_document) {
            std::string const new_name = get_filename_from_user();
            std::thread t(edit_document, new_name);
            t.detach();
        } else {
            process_user_input(cmd);
        }
    }
}

void f(int i, std::string const &s);
std::thread t(f, 3, "hello"); // Copying arguments by default
