#include "YATU.h"

void YRUN_TESTS(uint64_t test_number, YTEST tests[], FILE* f){

    out_file = f;
    
    passed_test = 0;

    clock_t start, diff;
    double sec;
    
    for(int i=0;i<test_number;i++){

        passed_assert = 0;
        unpassed_assert = 0;
        fprintf(out_file,"#################################################################\n");
        fprintf(out_file,"[-] Test: %s\n", tests[i].test_name);    
        
        start = clock();
        tests[i].test_func();
        diff = clock()-start;
        sec = (double)diff *1000.0/ (double)CLOCKS_PER_SEC;

        if((passed_assert+unpassed_assert)!=0){
            fprintf(out_file,"[-] End Test (%.2g milliseconds) %s: %d/%d passed (%.4g%)\n",sec,tests[i].test_name,passed_assert,passed_assert+unpassed_assert,(double)passed_assert/(double)(passed_assert+unpassed_assert)*100.0);
            if(passed_assert/(passed_assert+unpassed_assert)==1) passed_test++;
        }else{
            fprintf(out_file,"[-] End Test (%.2g milliseconds) %s: there aren't assert!\n",sec,tests[i].test_name);
            passed_test++;
        }
        fprintf(out_file,"#################################################################\n\n");
    }
    fprintf(out_file,"#################################################################\n[-]\t\t\tRESUME\n");
    if(test_number!=0){
        fprintf(out_file,"[-] Total Tests:\t%d\n", test_number);
        fprintf(out_file,"[-] Passed Tests:\t%d\n", passed_test);
        fprintf(out_file,"[-] Failed Tests:\t%d\n", test_number-passed_test);
        fprintf(out_file,"[-] Passed/Total (%):\t%.4g%\n", (double)passed_test/(double)test_number*100.0);
    }else
        fprintf(out_file,"[!] Nothing to test!\n");
    fprintf(out_file,"#################################################################\n");
    
}

void YASSERT(bool condition){
    if(condition){
        passed_assert++;
        fprintf(out_file, "[?]\tAssert %d passed\n",passed_assert+unpassed_assert);
    }else{
        unpassed_assert++;
        fprintf(out_file, "[!]\tAssert %d failed!\n",passed_assert+unpassed_assert);
    }
}