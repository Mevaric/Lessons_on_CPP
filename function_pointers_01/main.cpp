#include <iostream>

struct Renderer
{
	int x, y, z;
	void(*submit) (struct Renderer *self, int x, int y, int z);
	void(*flush) (struct Renderer *self);
};

void submit2d(Renderer *self, int x, int y,int z)
{
	self->x = x;
	self->y = y;
	self->z = z;

	printf("Submited data: %d, %d\n", x, y);
}
void flush2d(Renderer *self)
{
	printf("Flushing 2d renderer data: %d, %d\n", self->x, self->y);
}
void flushInit2d(Renderer *self)
{
	self->flush = flush2d;
}
void submitInit2d(Renderer *self)
{
	self->submit = submit2d;
}
void submit3d(Renderer *self, int x, int y, int z)
{
	self->x = x;
	self->y = y;
	self->z = z;

	printf("Submited data: %d, %d, %d\n", x, y,z);
}
void flush3d(Renderer *self)
{
	printf("Flushing 3d renderer data: %d, %d, %d\n", self->x, self->y, self->z);
}
void flushInit3d(Renderer *self)
{
	self->flush = flush3d;
}
void submitInit3d(Renderer *self)
{
	self->submit = submit3d;
}
int main() {

	Renderer r2d, r3d;
	submitInit2d(&r2d);
	submitInit3d(&r3d);
	flushInit3d(&r3d);
	flushInit2d(&r2d);

	submit2d(&r2d, 10, 5,0);
	flush2d(&r2d);

	submit3d(&r3d, 10, 40, 9);
	flush3d(&r3d);

	getchar();
	return 0;
}