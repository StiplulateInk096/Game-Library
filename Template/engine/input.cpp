int input() {
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_SPACE]){
	    return 69;
	}
	return 0;
}
