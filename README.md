## berry-intl: Berry bindings for GNU gettext

berry-intl is a Berry binding library for [GNU gettext](https://www.gnu.org/software/gettext).

It runs on GNU/Linux and requires [Berry](https://github.com/Skiars/berry/) (>=0.1.10)

_Authored by:_ _[Díaz Devera Víctor Diex Gamar (Máster Vitronic)](https://www.linkedin.com/in/Master-Vitronic)_

[![Berry logo](./docs/berry.png)](https://github.com/Skiars/berry/)

#### License

GPL license . See [LICENSE](./LICENSE).

#### Documentation

See the [Reference Manual](https://vitronic.gitlab.io/berry-intl/).



#### Getting and installing

```sh
$ git clone https://gitlab.com/vitronic/berry-intl.git
$ cd berry-intl
berry-intl$ make
berry-intl$ make install # or 'sudo make install' (Ubuntu)
```

#### Example

```ruby
#- Script: test.be

import intl; _  = intl.gettext


intl.setlocale("LC_ALL","");
intl.bindtextdomain("test", "./locales");
intl.textdomain("test");

print(_("Hello World"))
print(_("Good night"))
print(_("Amount"))
print(_("YES"))

```

The script can be executed at the shell prompt with the standard Berry interpreter:

```shell
$ LC_ALL=es_ES berry test.be
Hola Mondo
Buenas noches
Monto
SI
```

```shell
$ LC_ALL=fr_FR berry test.be
Bonjour le monde
Bonne nuit
Montant
OUI
```

```shell
$ LC_ALL=zh_CN berry test.be
你好，世界
晚上好
数额
是

```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
