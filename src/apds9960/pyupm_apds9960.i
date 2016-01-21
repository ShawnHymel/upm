// Include doxygen-generated documentation
%include "pyupm_doxy2swig.i"
%module pyupm_apds9960
%include "../upm.i"

%feature("autodoc", "3");

%include "apds9960.h"
%{
    #include "apds9960.h"
%}