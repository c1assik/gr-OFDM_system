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

#ifndef INCLUDED_OFDM_SYSTEM_EQUALIZE_CPP_H
#define INCLUDED_OFDM_SYSTEM_EQUALIZE_CPP_H

#include <OFDM_system/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace OFDM_system {

    /*!
     * \brief <+description of block+>
     * \ingroup OFDM_system
     *
     */
    class OFDM_SYSTEM_API Equalize_cpp : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<Equalize_cpp> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of OFDM_system::Equalize_cpp.
       *
       * To avoid accidental use of raw pointers, OFDM_system::Equalize_cpp's
       * constructor is in a private implementation
       * class. OFDM_system::Equalize_cpp::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace OFDM_system
} // namespace gr

#endif /* INCLUDED_OFDM_SYSTEM_EQUALIZE_CPP_H */

