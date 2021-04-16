/* -*- c++ -*- */

#define OFDM_SYSTEM_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "OFDM_system_swig_doc.i"

%{
#include "OFDM_system/OFDM_.h"
#include "OFDM_system/Equalize_cpp.h"
#include "OFDM_system/Equalize_sync.h"
%}

%include "OFDM_system/OFDM_.h"
GR_SWIG_BLOCK_MAGIC2(OFDM_system, OFDM_);

%include "OFDM_system/Equalize_cpp.h"
GR_SWIG_BLOCK_MAGIC2(OFDM_system, Equalize_cpp);
%include "OFDM_system/Equalize_sync.h"
GR_SWIG_BLOCK_MAGIC2(OFDM_system, Equalize_sync);
