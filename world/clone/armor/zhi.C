// by mhsj@gslxz 2001/3/12
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name(HIR"�ǻ�֮��"NOR, ({"zhihui pao","cloth"}));
  set("value", 250000);
      set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",MAG "��˵,�������ͻ�ӵ��������ǻۡ�\n" NOR);
    set("material", "cloth");
    set("unit", "��");
    set("armor_prop/armor", 40);
  set("armor_prop/intelligence", 10);
 }
  setup();
}
