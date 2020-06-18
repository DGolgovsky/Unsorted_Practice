#include <gst/gst.h>

int main(int argc, char *argv[]) {
	const gchar *nano;
	guint major, minor, micro, nano_int;

	/* Инициализация GStreamer, игнорируя любые аргументы */
	gst_init(NULL, NULL);
	if (gst_is_initialized())
		g_print("GStreamer library successfully initialized\n");

	/* Выводим версию при компиляции */
	if (GST_VERSION_NANO == 0)
		nano = "";
	else if (GST_VERSION_NANO == 1)
		nano = "(GIT)";
	else
		nano = "(Prerelease)";
	g_print("Compile time version:   %d.%d.%d %s\n", GST_VERSION_MAJOR, GST_VERSION_MINOR, GST_VERSION_MICRO, nano);

	/* Выводим runtime-версию */
	gst_version(&major, &minor, &micro, &nano_int);

	if (nano_int == 0)
		nano = "";
	else if (nano_int == 1)
		nano = "(GIT)";
	else
		nano = "(Prerelease)";
	g_print("Runtime version:        %d.%d.%d %s\n", major, minor, micro, nano);

	/* Выводим runtime-версию в виде готовой строки */
	g_print("String runtime version: %s\n", gst_version_string());
	return 0;
}
