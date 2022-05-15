#include "boy.h"
/**用LAST_SIGNAL来表示最后一个信号（不用实现的信号）是一种非常良好的编程风格**/
enum { BOY_BORN, LAST_SIGNAL };
static gint boy_signals[LAST_SIGNAL] = { 0 };
static void boy_cry (void);
static void boy_born(void);
static void boy_init(Boy *boy);
static void boy_class_init(BoyClass *boyclass);
 
/**g_type_register_static函数用来注册对象的类型，它的第一个参数是表示此对象的父类的对象类型，我们这里是G_TYPE_OBJECT，这个宏用来表示GObject的父类；
 * 第二个参数表示此对象的名称，这里为"Boy"；
 * 第三个参数是此对象的GTypeInfo结构型指针，这里赋值为&boyinfo；
 * 第四个参数是对象注册成功后返回此对象的整型ID标识。 **/
GType boy_get_type(void)
{
    static GType boy_type = 0;
    if(!boy_type) {
        static const GTypeInfo boy_info = {
            sizeof(BoyClass),
            NULL,NULL,
            (GClassInitFunc)boy_class_init,
            NULL,NULL,
            sizeof(Boy),
            0,
            (GInstanceInitFunc)boy_init
        };
        boy_type = g_type_register_static(G_TYPE_OBJECT,"Boy",&boy_info,0);
    }
    return boy_type;
}
/**boy_init和boy_class_init，它们分别用来初始化实例结构和类结构。它们并不被在代码中明显调用，
 * 关键是将其用宏转换为地址指针，然后赋值到GTypeInfo结构中，然后由GType系统自行处理，
 * 同时将它们定义为静态的也是非常必要的。 **/
static void boy_init(Boy *boy)
{
    boy->age = 0;
    boy->name = "none";
    boy->cry = boy_cry;
}
static void boy_class_init(BoyClass *boyclass)
{
    boyclass->boy_born = boy_born;
    /**Boy对象定义了一个信号BOY_BORN，在对象创建时发出，表示Boy对象诞生。
    *同时还需要定义静态的整型指针数组来保存信号的标识
    **/
    boy_signals[BOY_BORN] = g_signal_new("boy_born",
                BOY_TYPE,
                G_SIGNAL_RUN_FIRST,
                G_STRUCT_OFFSET(BoyClass,boy_born),
                NULL,NULL,
                g_cclosure_marshal_VOID__VOID,
                G_TYPE_NONE, 0, NULL);
}
Boy *boy_new(void)
{
    Boy *boy;
    boy = g_object_new(BOY_TYPE, NULL);
    //g_signal_emit向指定义对象的实例发射信号
    g_signal_emit(boy, boy_signals[BOY_BORN], 0);
    return boy;
}
int boy_get_age(Boy *boy)
{
    return boy->age;
}
void boy_set_age(Boy *boy, int age)
{
    boy->age = age;
}
char *boy_get_name(Boy *boy)
{
    return boy->name;
}
void boy_set_name(Boy *boy, char *name)
{
    boy->name = name;
}
Boy*  boy_new_with_name(gchar *name)
{
    Boy *boy;
    boy = boy_new();
    boy_set_name(boy, name);
    return boy;
}
Boy*  boy_new_with_age(gint age)
{
    Boy* boy;
    boy = boy_new();
    boy_set_age(boy, age);
    return boy;
}
Boy *boy_new_with_name_and_age(gchar *name, gint age)
{
    Boy *boy;
    boy = boy_new();
    boy_set_name(boy,name);
    boy_set_age(boy,age);
    return boy;
}
static void boy_cry (void)
{
    g_print("---The Boy is crying......\n");
}
static void boy_born(void)
{
    g_print("---Message : A boy was born.\n");
}
void boy_info(Boy *boy)
{
    g_print("---The Boy name is %s\n", boy->name);
    g_print("---The Boy age is %d\n", boy->age);
}