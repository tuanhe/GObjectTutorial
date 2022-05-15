#ifndef _BOY_H_
#define _BOY_H_
#include <glib-object.h>
/**BOY_TYPE宏封装了boy_get_type函数，可以直接取得并替代Boy对象的ID标识；
 * BOY(obj)宏是G_TYPE_CHECK_INSTANCE_CAST宏的再一次封装，目的是将一个Gobject对象强制转换为Boy对象
**/
#define BOY_TYPE (boy_get_type())
#define BOY(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), BOY_TYPE, Boy))
 
typedef struct _Boy Boy;
typedef struct _BoyClass BoyClass;
/**结构类型_Boy是Boy对象的实例，就是说我们每创建一个Boy对象，也就同时创建了一个Boy结构。
 * Boy对象中的parent表示此对象的父类，GObject系统中所有对象的共同的根都是GObject类，所以这是必须的；
 * 其它的成员可以是公共的，这里包括表示年龄的age，表示名字的name和表示方法的函数指针cry，
 * 外部代码可以操作或引用它们。
**/
struct _Boy
{
    GObject parent;
    gint age;
    gchar *name;
    void (*cry)(void);
};
/**结构类型_BoyClass是Boy对象的类结构，它是所有Boy对象实例所共有的。
 * BoyClass中的parent_class是GObjectClass，同GObject是所有对象的共有的根一样，GObejctClass是所有对象的类结构的根。
 * 在BoyClass中我们还定义了一个函数指针boy_born，也就是说这一函数指针也是所有Boy对象实例共有的，
 * 所有的Boy实例都可以调用它；同样，如果需要的话，你也可以在类结构中定义其它数据成员。
**/
struct _BoyClass
{
    GObjectClass parent_class;
    void (*boy_born)(void);
};
/**其余的函数定义包括三种：一种是取得Boy对象的类型ID的函数boy_get_type，这是必须有的；
 * 另一种是创建Boy对象实例的函数boy_new和boy_new_with_*，这是非常清晰明了的创建对象的方式，当然你也可以用g_object_new函数来创建对象；
 * 第三种是设定或取得Boy对象属性成员的值的函数boy_get_*和boy_set_*。
 * 正常情况下这三种函数都是一个对象所必需的，另外一个函数boy_info用来显示此对象的当前状态**/
GType boy_get_type(void);
Boy *boy_new(void);
gint boy_get_age(Boy *boy);
void boy_set_age(Boy *boy, int age);
char *boy_get_name(Boy *boy);
void boy_set_name(Boy *boy, char *name);
Boy *boy_new_with_name(gchar *name);
Boy * boy_new_with_age(gint age);
Boy * boy_new_with_name_and_age(gchar *name, gint age);
void  boy_info(Boy *boy);
#endif // _BOY_H_