void init() {
	SDL_Init(SDL_INIT_EVERYTHING);
}
void initWindow(int w, int h) {
	window = SDL_CreateWindow(
		"unnamed game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		w,
		h,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
	);
	renderer = SDL_CreateRenderer(
		window,
		0,
		0
	);
}
