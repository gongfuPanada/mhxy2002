// rankd.c
// 1996-02-15 dts ranking related to "shen"

#include <ansi.h>

string query_rank(object ob)
{
        mapping fam;

        int shen;
        int budd;
        int age;

        if( ob->is_ghost() )
                return HIB "�� ��  �� ��" NOR;

        shen = ob->query("shen");
        age = ob->query("age");
        if ( (fam = ob->query("family")) && (fam["family_name"] == "������"
                || fam["family_name"] == "������"
                || fam["family_name"] == "������"
                || fam["family_name"] == "ѩɽ��"
                || fam["family_name"] == "��ɽ��"
                ))
                budd = ob->query_skill("buddhism",1);

        switch(ob->query("gender")) {
        case "Ů��":
                switch(wizhood(ob)) {
                case "(admin)":
                        return HIM "�� ��  �� ��" NOR;
                case "(arch)":
                        return HIY "�� ��  �� ��" NOR;
                case "(wizard)":
                        return HIG "�� ��  Ů ��" NOR;
                case "(apprentice)":
                        return HIC "�� С��Ů ��" NOR;
                case "(immortal)":
                        return HIC "�� ��  Ů ��" NOR;
                default:
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return "�� ɱ��ħ ��";
                        if ((int)ob->query("thief") > 10 )
                                return "�� ��  �� ��";
                        if (shen >= 100000)
                                return HIC "������Ů����" NOR;
//                        else if (shen >= 10000)
//                                return HIC "�� ��Ů�� ��" NOR;
//                        else if (shen >= 1000)
//                                return HIC "�� Ů  �� ��" NOR;
//                        else if (shen >= 100)
//                                return HIC "�� Ů���� ��" NOR;
                        else if (shen <= -100000)
                                return HIC "�� Ůħ�� ��" NOR;
//                        else if (shen <= -10000)
//                                return HIC "�� ��Ůħ ��" NOR;
//                        else if (shen <= -1000)
//                                return HIC "�� Ů  ħ ��" NOR;
//                        else if (shen <= -100)
//                                return HIC "�� Ů��ħ ��" NOR;
                        else
                        switch(ob->query("class")) {
                        case "bonze":
                             if (budd >= 150)
                                return HIY "�� ��  �� ��" NOR;
                             else if (budd >= 120)
                                return HIY "�� ʥ  �� ��" NOR;
                             else if (budd >= 90)
                                return HIY "�� ��  �� ��" NOR;
                             else if (budd >= 60)
                                return HIC "�� ��  �� ��" NOR;
                             else if (budd >= 30)
                                return HIG "�� ʦ  ̫ ��" NOR;
                             else if (age <= 16)
                                return "�� С��� ��";
                             else
                                return "�� ��  �� ��";
                        case "taoist":
                             if (age <= 16)
                                return "�� С���� ��";
                             else if (age <= 30)
                                return "�� ��  �� ��";
                             else
                                return "�� ��  Ů ��";
                        case "bandit":
                                return "�� Ů���� ��";
                        case "dancer":
                                return "�� ��  �� ��";
                        case "scholar":
                             if (age <= 16)
                                return "�� Ůѧͯ ��";
                             else if (age <= 30)
                                return "�� ��  Ů ��";
                             else
                                return "�� Ůѧʿ ��";
                        case "officer":
                                return "�� Ů  �� ��";
                        case "fighter":
                                return "�� Ů���� ��";
                        case "swordsman":
                                return "�� Ů��ʿ ��";
                        case "alchemist":
                                return "�� Ů��ʿ ��";
                        case "shaman":
                                return "�� Ů��ҽ ��";
                        case "beggar":
                                return "�� Ů�л� ��";
                        case "prostitute":
                                return "�� ��  Ů ��";
                        default:
                                if (age <= 16)
                                    return "�� ��  Ů ��";
                                else
                                    return "�� ��  �� ��";
                        }
                }
        default:
                switch(wizhood(ob)) {
                case "(admin)":
                        return HIM "�� ��  �� ��" NOR;
                case "(arch)":
                        return HIY "�� ��  �� ��" NOR;
                case "(wizard)":
                        return HIG "�� ��  �� ��" NOR;
                case "(apprentice)":
                        return HIC "�� ɢ  �� ��" NOR;
                case "(immortal)":
                        return HIC "�� ��  �� ��" NOR;
                default:
                        if (shen >= 100000)
                                return HIC "������������" NOR;
//                        else if (shen >= 10000)
//                                return HIC "�� ��  �� ��" NOR;
//                        else if (shen >= 1000)
//                                return HIC "�� ��  �� ��" NOR;
//                        else if (shen >= 100)
//                                return HIC "�� ��  �� ��" NOR;
                        else if (shen <= -100000)
                                return HIC "�� ħ  �� ��" NOR;
//                        else if (shen <= -10000)
//                                return HIC "�� ��  ħ ��" NOR;
//                        else if (shen <= -1000)
//                                return HIC "�� ħ  ͷ ��" NOR;
//                        else if (shen <= -100)
//                                return HIC "�� ��  ħ ��" NOR;
//                        else
                        if (((int)ob->query("PKS") > 100) &&
                            ((int)ob->query("PKS") > (int)ob->query("MKS")))
                                return "�� ɱ��ħ ��";
                        if ((int)ob->query("thief") > 10 )
                                return "�� ��  �� ��";
                        else
                                switch(ob->query("class")) {
                                case "bonze":
                                        if (budd >= 150)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (budd >= 120)
                                                return HIY "�� ʥ  ɮ ��" NOR;
                                        else if (budd >= 90)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (budd >= 60)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (budd >= 40)
                                                return HIY "�� ��  ʦ ��" NOR;
                                        else if (budd >= 30)
                                                return HIY "�� ��  �� ��" NOR;
                                        else if (age <= 16)
                                                return HIY "�� С���� ��" NOR;
                                        else
                                                return "�� ɮ  �� ��";
                                case "taoist":
                                        if (ob->query_skill("taoism",1)>100)
                                           return "�� ��  �� ��";
                                        else if (age <= 16)
                                           return "�� С��ʿ ��";
                                        else if (age <= 30)
                                           return "�� ��  ʿ ��";
                                        else
                                           return "�� ��  �� ��";
                                case "bandit":
                                        return "�� ��  �� ��";
                                case "scholar":
                                     if (age <= 16)
                                        return "�� ѧ  ͯ ��";
                                     else if (age <= 45)
                                        return "�� ��  �� ��";
                                     else
                                        return "�� ����� ��";
                                case "officer":
                                        return "�� ��  �� ��";
                                case "fighter":
                                        return "�� ��  �� ��";
                                case "swordsman":
                                        return "�� ��  ʿ ��";
                                case "alchemist":
                                        return "�� ��  ʿ ��";
                                case "shaman":
                                        return "�� ��  ҽ ��";
                                case "beggar":
                                        if (age <= 16)
                                            return "�� С�л� ��";
                                        else
                                            return "�� �л��� ��";
                                case "eunach":
                                        budd = ob->query_skill("pixie-jian",1);
                                        if (budd >= 110)
                                                return HIY "�����ڸ��֡�" NOR;
                                        else if (budd >= 100)
                                                return HIY "�������򻧡�" NOR;
                                        else if (budd >= 90)
                                                return HIY "������ǧ����" NOR;
                                        else if (budd >= 80)
                                                return HIY "�������ٻ���" NOR;
                                        else if (budd >= 70)
                                                return HIY "������ʮ����" NOR;
                                        else if (budd >= 60)
                                                return HIY "������������" NOR;
                                        else return "�� ��  �� ��";
                                case "prostitute":
                                        return "�� ��  �� ��";
                                default:
                                        if (age <= 16)
                                            return "�� ��  �� ��";
                                        else
                                            return "�� ƽ  �� ��";
                                }
                }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ̫";
                                else return "ʦ̫";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С�ɹ�";
                                else return "�ɹ�";
                                break;
                        default:
                                if( age < 18 ) return "С����";
                                else if( age < 30 ) return "����";
                                else if( age < 40 ) return "����";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ��";
                                else return "��ʦ";
                                break;
                        case "taoist":
                                if( age < 18 ) return "����";
                                else return "����";
                                break;
                        case "scholar":
                                if( age < 18 ) return "С�๫";
                                else if( age < 50 ) return "�๫";
                                else return "������";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "С�ϵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ǰ��";
                                break;
                        default:
                                if( age < 20 ) return "С�ֵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ү��";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "С����";
                                if( age < 30 ) return "����";
                                else return "������";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С��Ů";
                                if( age < 30 ) return "��Ů";
                                else return "������";
                                break;
                        default:
                                if( age < 18 ) return "С��Ƥ";
                                if( age < 25 ) return "С����";
                                if( age < 40 ) return "������";
                                else return "����̫��";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "С��ͺ";
                                if( age < 50 ) return "��ͺ¿";
                                else return "��ͺ¿";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С��ë";
                                if( age < 30 ) return "��ţ����";
                                else return "����ë";
                                break;
                        case "scholar":
                                if( age < 18 ) return "С�����";
                                else if( age < 50 ) return "�������";
                                else return "��ͯ��";
                                break;
                        default:
                                if( age < 20 ) return "С���˵�";
                                if( age < 30 ) return "ֱ����";
                                if( age < 50 ) return "����";
                                if( age < 80 ) return "��ƥ��";
                                else return "�ϲ���";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        case "taoist":
                                return "ƶ��";
                                break;
                        default:
                                if( age < 20 ) return "СŮ��";
                                if( age > 50 ) return "����";
                                else return "���";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "С��";
                                if( age < 40 ) return "ƶɮ";
                                else return "����";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С��";
                                if( age < 30 ) return "ƶ��";
                                else return "�ϵ�";
                                break;
                        case "scholar":
                                if( age < 30 ) return "����";
                                else return "����";
                                break;
                        default:
                                if( age < 50 ) return "����";
                                else return "��ͷ��";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        case "taoist":
                                return "���ɹ�";
                                break;
                        default:
                                if( age < 20 ) return "������";
                                if( age < 30 ) return "��������";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "�������";
                                else return "�Ϻ�����";
                                break;
                        case "taoist":
                                if( age < 30 ) return "��ɽ��";
                                return "�ϵ���";
                                break;
                        case "scholar":
                                if( age < 50 ) return "���๫";
                                else return "�Ϸ�����";
                                break;
                        default:
                                if( age < 20 ) return "����ү��";
                                if( age < 40 ) return "��ү��";
                                else return "����";
                                break;
                        }
        }
}
string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
        }
}

string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
        }
}
