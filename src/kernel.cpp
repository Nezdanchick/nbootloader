extern "C" void halt();
extern "C" void print_ok();
extern "C" {
	void kernel_main(void) {
		print_ok();
		halt();
	}
}
