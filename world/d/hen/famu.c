// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "��ľ��");
  set ("long", @LONG

        ������������� [1;32m fa_mu [m ȥ����һЩ��ľ��������~~��

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"syroad4",
]));
        setup();
}

void init()
{
                add_action("do_work","fa_mu");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-15);
        ob->add("hen/happy",-10);
        ob->add("hen/satisfy",-10);
        ob->add("hen/dirty",12);

        cat(LOGER);

        if( time() - ob->query("hen/last_famu") < 180 )
        {
        write("����С���������ظ���ͬһ�����顣\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",400+random(20));
        ob->set("hen/last_famu",time());
        ob->add("hen/max_life",3);
        ob->add("hen/mold",-3);
        return 1;
}