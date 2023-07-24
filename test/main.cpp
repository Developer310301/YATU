#include "YATU.h"

void test_add(){
    YASSERT((2+2)==4);
}

void test_sub(){
    YASSERT((2-2)==0);
}

int main(){
    
    YTEST add_test{test_add,"Test Add"};
    YTEST sub_test{test_sub,"Test Sub"};
    YTEST tests[] = {add_test,sub_test};
    YRUN_TESTS(2,tests);

    return 0;
}