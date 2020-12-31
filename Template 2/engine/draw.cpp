void fill(int r,int g,int b,int a)
{
    SDL_SetRenderDrawColor(
    	renderer,
    	r, g, b, a
    );
}
void fillC(colour c) {
	fill(c.r, c.g, c.b, c.a);
}
void background(int r,int g,int b,int a)
{
	fill(r,g,b,a);
	SDL_RenderClear(renderer);
}
void applyDraw()
{
	SDL_RenderPresent(renderer);
}

