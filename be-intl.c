/*

  be-intl.c - Berry bindings to gettext

  Copyright (c) 2021, Díaz Devera Víctor <mastervitronic@gmail.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

/***
 * Berry bindings to gettext
 *
 * This documentation is partial, and doesn't cover all functionality yet.
 * @module intl
 * @author Díaz Devera Víctor (Máster Vitronic) <mastervitronic@gmail.com>
 */


#define BERRY_MODULE
#include <berry/berry.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <libintl.h>
#include <locale.h>
#define _(STRING) gettext(STRING)
#define VERSION "1.0.0"

/***
 * Berry gettext library version.
 * @function version
 * @treturn string version string "major.minor.revision"
 */
static int m_version(bvm *vm) {
    be_pushstring(vm,  VERSION);
    be_return(vm);
}

/***
 * Look up msgid in the current default message catalog for the current
 * LC_MESSAGES locale.  If not found, returns msgid itself (the default
 * text)
 * @function gettext
 * @tparam string msgid
 * @treturn string result
 */
static int m_gettext(bvm *vm) {
    const char * msgid  = be_tostring(vm, 1);

    be_pushstring(vm,  _(msgid));
    be_return(vm);
}

/***
 * Similar to 'gettext' but select the plural form corresponding to the
 * number count. 
 * @function ngettext
 * @tparam string single
 * @tparam string plural
 * @tparam int count
 * @treturn string result
 */
static int m_ngettext(bvm *vm) {
    const char * single  = be_tostring(vm, 1);
    const char * plural  = be_tostring(vm, 2);
    const int count      = be_toint(vm, 3);

    be_pushstring(vm,  ngettext(single,plural,count));
    be_return(vm);
}

/***
 * Support for the locale chosen by the user. 
 * @tparam string category
 * @tparam string locale
 * @function setlocale
 */
static int m_setlocale(bvm *vm) {
    const char * category = be_tostring(vm, 1);
    const char * locale   = be_tostring(vm, 2);
    int number;
    if (strcmp(category, "LC_CTYPE") == 0) {
        number = 0;
    } else if (strcmp(category, "LC_NUMERIC") == 0) {
        number = 1;
    } else if (strcmp(category, "LC_TIME") == 0) {
        number = 2;
    } else if (strcmp(category, "LC_COLLATE") == 0) {
        number = 3;
    } else if (strcmp(category, "LC_MONETARY") == 0) {
        number = 4;
    } else if (strcmp(category, "LC_MESSAGES") == 0) {
        number = 5;
    } else if (strcmp(category, "LC_ALL") == 0) {
      number = 6;
    }

    setlocale(number, locale);
    be_return(vm);
}

/***
 * Specify that the domainname message catalog will be found
 * in dirname rather than in the system locale data base.
 * @tparam string domainname
 * @tparam string dirname
 * @function bindtextdomain
 */
static int m_bindtextdomain(bvm *vm) {
    const char * domainname = be_tostring(vm, 1);
    const char * dirname    = be_tostring(vm, 2);

    bindtextdomain(domainname, dirname);
    be_return(vm);
}

/***
 * Set the current default message catalog to domainname.
 * If domainname is null, return the current default.
 * If domainname is "", reset to the default of "messages". 
 * @tparam string domainname
 * @function textdomain
 */
static int m_textdomain(bvm *vm) {
    const char * domainname  = be_tostring(vm, 1);
    if (strcmp(domainname, "nil") == 0){
      domainname = NULL;
    }

    textdomain(domainname);
    be_return(vm);
}


static void bind_member(bvm *vm, const char *attr, bntvfunc f) {
    be_pushntvfunction(vm, f);
    be_setmember(vm, -2, attr);
    be_pop(vm, 1);
}

int berry_export(bvm *vm) {
    be_newmodule(vm);
    be_setname(vm, -1, "intl");
    bind_member(vm, "version", m_version);
    bind_member(vm, "gettext", m_gettext);
    bind_member(vm, "ngettext", m_ngettext);
    bind_member(vm, "setlocale", m_setlocale);
    bind_member(vm, "bindtextdomain", m_bindtextdomain);
    bind_member(vm, "textdomain", m_textdomain);

    be_return(vm);
}
