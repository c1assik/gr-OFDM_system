#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2021 gr-OFDM_system author.
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#


import numpy
from matplotlib import pyplot as plt
from gnuradio import gr

class Equalize_py(gr.basic_block):
    """
    docstring for block Equalize_py
    """
    def __init__(self):
        gr.basic_block.__init__(self,
            name="Equalize_py",
            in_sig=[(numpy.complex64,64) ],
            out_sig=[numpy.complex64 ])

    def forecast(self, noutput_items, ninput_items_required):
        #setup size of input_items[i] for work call
        for i in range(len(ninput_items_required)):
            ninput_items_required[i] = noutput_items

    def general_work(self, input_items, output_items):
        in0 = input_items[0]
        out = output_items[0][:]

        # plt.plot(numpy.abs(in0[0][:]))
        # plt.show()
        for i in range(0, len(in0[0])):
            out[:] = in0[0][i]
        # preamb = [0., 0., 0., 0., 0., 0., 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., -1.41421356, 0., -1.41421356, 0., -1.41421356, 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., -1.41421356, 0., -1.41421356, 0., -1.41421356, 0., -1.41421356, 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., 1.41421356, 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., 1.41421356, 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., 1.41421356, 0., 1.41421356, 0., 0., 0., 0., 0., 0.]
 
        # # rx_preamb = in0[64:64*2]
 
   
        # for tag in tags:
            
        #     key = pmt.to_python(tag.key) # convert from PMT to python string
        #     value = pmt.to_python(tag.value) # Note that the type(value) can be several things, it depends what PMT type it was
           
        #     if(key == "time_est"):

        #         # ch_estim = rx_preamb/preamb
        #         # eq = rx_preamb/ch_estim
        #         plt.plot(numpy.abs((rx_preamb)))
        #         plt.show()

        #         # plt.plot(numpy.abs(in0))
        #         # plt.show()
        #         # print('value:',value)



       
        return len(output_items[0])
