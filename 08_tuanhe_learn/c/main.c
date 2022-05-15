#include <glib.h>
#include "boy.h"
#include "man.h"
 
int main(int argc, char *argv[])
{
    Boy *tom, *peter;
    Man *green, *brown;
    #if !GLIB_CHECK_VERSION(2,35,0)
    g_type_init ();
    #endif
    g_type_init();//注意，初始化类型系统，必需
    g_print("**********************\n");
    tom = boy_new_with_name("Tom");
    tom->cry();
    boy_info(tom);
    g_print("**********************\n");
    peter = boy_new_with_name_and_age("Peter", 10);
    peter->cry();
    boy_info(peter);
    g_print("**********************\n");
    g_print("######################\n");
    green = man_new();
    /**设定Man对象的name属性用到其父对象Boy的方法**/
    boy_set_name(BOY(green), "Green");
    boy_set_age(BOY(green), 28);
    man_set_job(green, "Doctor");
    man_info(green);
    green->bye();
    g_print("######################\n");
    brown = man_new_with_name_age_and_job("Brown", 30, "Teacher");
    man_info(brown);
    brown->bye();
    g_print("######################\n");
    return TRUE;
}