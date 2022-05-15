#ifndef _MAN_H_
#define _MAN_H_
/**********Man继承自Boy对象，Man对象在Boy对象的基础上又增加了一个属性job和一个方法bye***********/
#include "boy.h"
 
#define MAN_TYPE (man_get_type())
#define MAN(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), MAN_TYPE, Man))
typedef struct _Man Man;
typedef struct _ManClass ManClass;
struct _Man
{
    Boy parent;
    gchar *job;
    void (*bye)(void);
};
struct _ManClass
{
    BoyClass parent_class;
};
 
GType man_get_type();
Man *man_new(void);
gchar *man_get_job(Man *man);
void man_set_job(Man *man, gchar *job);
Man *man_new_with_name_age_and_job(gchar *name, gint age, gchar *job);
void man_info(Man *man);
 
#endif // _MAN_H_