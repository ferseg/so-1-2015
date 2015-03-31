#include "../Headers/client.h"

int main()
{
	struct client *c1 = new_client(1,0);
	
	printf("%d\n%d\n%d\n",get_type(c1),get_sorting_method(c1),get_status(c1));
	
	return 0;
}
