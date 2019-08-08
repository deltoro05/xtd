[![console](docs/pictures/header.png)](https://gammasoft71.wixsite.com/xtd-console)

[![Build Status](https://travis-ci.org/gammasoft71/xtd.console.svg?branch=master)](https://travis-ci.org/gammasoft71/xtd.console)
[![Build status](https://ci.appveyor.com/api/projects/status/7i6t0xilki708d2s?svg=true)](https://ci.appveyor.com/project/gammasoft71/xtd-console)
[![codecov](https://codecov.io/gh/gammasoft71/xtd.console/branch/master/graph/badge.svg)](https://codecov.io/gh/gammasoft71/xtd.console)
[![Documentation](https://codedocs.xyz/gammasoft71/xtd.console.svg)](https://codedocs.xyz/gammasoft71/xtd.console/)
[![Website](https://img.shields.io/website-up-down-green-red/http/shields.io.svg?label=xtd-console%20website)](https://gammasoft71.wixsite.com/xtd-console)
[![license](https://img.shields.io/github/license/gammasoft71/xtd.console.svg)](LICENSE.md)
[![SourceForge Download console](https://img.shields.io/sourceforge/dt/console-cpp.svg)](https://sourceforge.net/projects/console-cpp/files/latest/download)
[![GitHub top language](https://img.shields.io/github/languages/top/gammasoft71/xtd.console.svg)](README.md)
[![Windows](https://img.shields.io/badge/os-Windows-004080.svg)](README.md)
[![macOS](https://img.shields.io/badge/os-macOS-004080.svg)](README.md)
[![Linux](https://img.shields.io/badge/os-Linux-004080.svg)](README.md)


# Features

* Simple common controls like label, button, check box, ...
* Complex common controls like rich text box, tree view, ...
* Simple containers like group box, panel, ...
* Complex containers like form, tab control, ...
* Various dialogs like message box, open file dialog, color dialog, ...
* Easy catch event from controls by using event and delegates classes.
* ...

For more information see [Documentation](docs).

# Examples

The following examples "Hello, world!" show how use form and button control, catch event click and show a message box.

src/forms_hello_world_console.cpp

```c++
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  application::enable_visual_styles();
  
  button button1;
  button1.text("Click me");
  button1.location({10, 10});
  button1.click += [&](const control& sender, const event_args& e) {
    message_box::show("Hello, World!");
  };
  
  form form1;
  form1.text("Hello World Form");
  form.controls().push_back(button1);
  
  application::run(form1);
}

```

For more examples see [examples](examples)

# Download and install

Before running examples you must download and install xtd.console. To download and install it read Downloads file.

