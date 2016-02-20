#include <weapon.h>
#include <ansi.h>

inherit STICK;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"玄铁重棍"NOR,({ "xuantie gun", "xuantie", "bang", "stick"}) );
        set_weight(70000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 10);
                set("no_give", "这是你的心血啊怎么能轻易送人呢?\n");
                set("sharpness", 9); 
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -12);
                set("treasure",1);
                set("wield_force", 1500);
                set("wield_maxforce", 2100);
                set("wield_str", 32);
                set("wield_msg", HIY"$N嗡的一声从腰间抽出玄铁重棍，但见寒气逼人，杀雾迷茫，
方圆之内轰然雷声滚滚，肃杀万分。\n"NOR);
                set("long", "此棍长七尺，黝黑黝黑由万年玄铁所铸，沉重无比，
杀气森然，实乃天下第一神兵。\n");                
                set("unwield_msg", BLU "$N将玄铁棍插回肩后，杀气顿减。\n" NOR);               
}
        init_stick(160);
        setup();
}
