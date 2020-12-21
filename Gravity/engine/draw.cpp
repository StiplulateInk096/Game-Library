int fill(int r,int g,int b,int a)
{
    SDL_SetRenderDrawColor(
    	renderer,
    	r, g, b, a
    );
	return 0;
}
int fillC(colour c) {
	fill(c.r, c.g, c.b, c.a);
	return 0;
}
int background(int r,int g,int b,int a)
{
	fill(r,g,b,a);
	SDL_RenderClear(renderer);
	return 0;
}
int applyDraw()
{
	SDL_RenderPresent(renderer);
	return 0;
}

