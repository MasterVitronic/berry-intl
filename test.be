#!/usr/bin/env berry

#-
 @filename  test.be
 @version   1.0
 @autor     Máster Vitronic <mastervitronic@gmail.com>
 @date      Tue Mar 30 16:20:53 -04 2021
 @licence   MIT licence
-#

#Usage : LC_ALL=zh_CN ./test.be


import intl; _ = intl.gettext


intl.setlocale("LC_ALL","")
intl.bindtextdomain("test", "./locales")
intl.textdomain("test")

print(_("Hello World"))
print(_("Good night"))
print(_("Amount"))
print(_("YES"))

