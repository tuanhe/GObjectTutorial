#include "man.h"
static void man_bye(void);
static void man_init(Man *man);
static void man_class_init(Man *man);
/**关键在于定义对象时将父对象实例定义为Boy，父类设定为BoyClass，在注册此对象时将其父对象类型设为BOY_TYPE。
 **/
GType man_get_type(void)
{
    static GType man_type = 0;
    if(!man_type) {
        static const GTypeInfo man_info = {
            sizeof(ManClass),
            NULL, NULL,
            (GClassInitFunc)man_class_init,
            NULL, NULL,
            sizeof(Man),
            0,
            (GInstanceInitFunc)man_init
        };
        /**在注册此对象时将其父对象类型设为BOY_TYPE**/
        man_type = g_type_register_static(BOY_TYPE, "Man", &man_info, 0);
    }
    return man_type;
}
static void man_init(Man *man)
{
    man->job = "none";
    man->bye = man_bye;
}
static void man_class_init(Man *man)
{
}
Man*  man_new(void)
{
    Man *man;
    man = g_object_new(MAN_TYPE, 0);
    return man;
}
gchar* man_get_job(Man *man)
{
    return man->job;
}
void  man_set_job(Man *man, gchar *job)
{
    man->job = job;
}
Man*  man_new_with_name_age_and_job(gchar *name, gint age, gchar *job)
{
    Man *man;
    man = man_new();
    boy_set_name(BOY(man), name);
    boy_set_age(BOY(man), age);
    man_set_job(man, job);
    return man;
}
static void man_bye(void)
{
    g_print("+++Goodbye everyone!\n");
}
/**在设定对象属性时如用到父对象的属性要强制转换下，如取得对象的name属性，就必须用BOY(obj)->name，
 *因为Man本身没有name属性，而其父对象Boy有，所以用BOY宏将其强制为Boy类型的对象。
**/
void man_info(Man *man)
{
    /**定义对象时将父对象实例定义为Boy，父类设定为BoyClass**/
    g_print("+++the man name is %s\n", BOY(man)->name);
    g_print("+++the man age is %d\n", BOY(man)->age);
    g_print("+++the man job is %s\n", man->job);
}