struct ext_struct {
	int b;
	int a;
	int c;
	int d;
	char e;
};

int set_a(struct ext_struct *p, int a)
{
	int temp = p->a;
	p->a = a;
	return temp;
}

struct ext_struct *ext_struct_malloc()
{
    static struct ext_struct ext;
    static int i = 0;
    if(i == 0) {
        i = 1;
        return &ext;
    } else {
        return 0;
    }
}
