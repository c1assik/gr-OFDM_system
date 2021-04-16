/* -*- c++ -*- */
/*
 * Copyright 2021 gr-OFDM_system author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "Equalize_cpp_impl.h"
#include <fstream>
#include <vector>

namespace gr {
  namespace OFDM_system {

    Equalize_cpp::sptr
    Equalize_cpp::make()
    {
      return gnuradio::get_initial_sptr
        (new Equalize_cpp_impl());
    }


    /*
     * The private constructor
     */
    Equalize_cpp_impl::Equalize_cpp_impl()
      : gr::block("Equalize_cpp",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {}

    /*
     * Our virtual destructor.
     */
    Equalize_cpp_impl::~Equalize_cpp_impl()
    {
    }

    void
    Equalize_cpp_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
       unsigned ninputs = ninput_items_required.size ();

         for(unsigned i = 0; i < ninputs; i++)
            ninput_items_required[i] = noutput_items;
    }

    int
    Equalize_cpp_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];

      int fft_len = 64; //ftt size 
      int k = 0;
      int preamb_count = 0;

      std::ofstream myfile;
      myfile.open("frame_rx.txt");
 

      std::vector<gr_complex> estim;
      std::vector<gr_complex> eq;
      const std::vector<gr_complex> sync_word = {0., 0., 0., 0., 0., 0., 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., -1.41421356, 0., -1.41421356, 0., -1.41421356, 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., -1.41421356, 0., -1.41421356, 0., -1.41421356, 0., -1.41421356, 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., 1.41421356, 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., 1.41421356, 0., 1.41421356, 0., -1.41421356, 0., 1.41421356, 0., 1.41421356, 0., 1.41421356, 0., 0., 0., 0., 0., 0.};


      for(int i = 0; i != fft_len; i++)
      {
        estim.push_back(std::isinf(std::abs(in[fft_len + i]/sync_word[k])) ? 0 : (in[fft_len + i]/sync_word[k]));
        //estim.push_back(in[64+i]);
        
        k++;
        if (k == fft_len) {k = 0;} 

        

         
      }

      for(int i = 7; i != estim.size(); i = i + 2)
      {
        estim[i+1] = estim[i];
      }

  
      for(int i = 0; i < (int)ninput_items[0]; i++)
      { 
       
        out[i] = (std::isinf(std::abs(in[i]/estim[k]))) ? 0 : (in[i]/estim[k]);
        //eq.push_back(std::isinf(std::abs(in[fft_len +  i]/estim[k])) ? 0 : (in[fft_len + i]/estim[k]));
        k++;
        if (k == fft_len) {k = 0;} 
       
      }

      
  
      
      //  for(int i = 0; i != estim.size(); i++)
      // {
        
      //   myfile << std::abs(estim[i]) << std::endl;
      
      // }


      // myfile.close();
    

      

      consume_each(1);
      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace OFDM_system */
} /* namespace gr */

