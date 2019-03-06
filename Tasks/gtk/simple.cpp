/*
 * This program will create an empty 200x200 pixel window
 *
 * compile:
 * g++ simple.cpp -o simple `pkg-config gtkmm-3.0 --cflags --libs`
 */

#include <gtkmm.h>

int main(int argc, char **argv)
{
    auto app = // Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create(argc, argv,
                "org.gtkmm.example.base");

    Gtk::Window window;
    window.set_default_size(200, 200);

    return app->run(window);
}
