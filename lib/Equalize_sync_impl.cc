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
#include "Equalize_sync_impl.h"

namespace gr {
  namespace OFDM_system {

    Equalize_sync::sptr
    Equalize_sync::make()
    {
      return gnuradio::get_initial_sptr
        (new Equalize_sync_impl());
    }


    /*
     * The private constructor
     */
    Equalize_sync_impl::Equalize_sync_impl()
      : gr::sync_block("Equalize_sync",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {}

    /*
     * Our virtual destructor.
     */
    Equalize_sync_impl::~Equalize_sync_impl()
    {
    }

    int
    Equalize_sync_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];

      std::vector<gr_complex> estim;
      
      std::ofstream myfile;
      myfile.open("frame_rx.txt");

      for(int i = 0; i < noutput_items; i++)
      { 
        out[i] = in[0];
       // estim.push_back(in[i]);
      }

      //        for(int i = 0; i != estim.size(); i++)
      // {
        
      //   myfile << std::abs(estim[i]) << std::endl;
      
      // }


      // myfile.close();

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace OFDM_system */
} /* namespace gr */

