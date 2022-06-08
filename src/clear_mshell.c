#include "minishell.h"

void    clear_mshell(t_shell *mshell)
{
//    t_env *del;
    t_command *buf;
    int i;
//
//    while(mshell->environment) {
//        del = mshell->environment;
//        mshell->environment = mshell->environment->next;
//        if (ft_strlen(del->value) > 0)
//            free(del->value);
//        free(del->key);
//        free(del);
//    }
//    mshell->lstcom = mshell->lstcom->head;
    while (mshell->lstcom)
    {
        i = 0;
        if (mshell->lstcom->command)
            free(mshell->lstcom->command);
        buf = mshell->lstcom;
        mshell->lstcom = mshell->lstcom->next;
        free(buf);
    }
    if (mshell->input)
        free(mshell->input);
    mshell->input = NULL;
}