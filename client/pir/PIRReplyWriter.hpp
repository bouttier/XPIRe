/* Copyright (C) 2014 Carlos Aguilar Melchor, Joris Barrier, Marc-Olivier Killijian
 * This file is part of XPIRe.
 *
 *  XPIRe is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  XPIRe is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XPIRe.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DEF_PIRREPLYWRITER
#define DEF_PIRREPLYWRITER

#include <iostream>
#include <boost/signals2.hpp>
#include <boost/thread.hpp>
#include <omp.h>
#include <unistd.h>

#include "crypto/PaillierAdapter.hpp"
#include "events/WriteEvent.hpp"
#include "events/MessageEvent.hpp"
#include "client/DESC.hpp"

#include "pir/PIRParameters.hpp"
#include "ClientDefines.hpp"
#include "GlobalConstant.hpp"
#include "shared_queue.hpp"

class PIRReplyWriter
{
  private:
    bool dontWrite;
    string filename, filePath;
		PIRParameters& pirParams;
		HomomorphicCrypto* cryptoMethod;
		shared_queue<char*> clearChunks;		
    static const std::string kDefaultFolder;

		boost::thread writeThread;
		boost::signals2::signal<void (WriteEvent&)>   &writeListeners; 
		boost::signals2::signal<void (MessageEvent&)> &messageListeners;
  public:
    PIRReplyWriter(PIRParameters& param, boost::signals2::signal<void ( WriteEvent& )> &writeListeners_, boost::signals2::signal<void (MessageEvent&)> &messageListeners_); 
    ~PIRReplyWriter();
    void writeAggregatedFileSecurely(uint64_t chosenElement, DESC catalog); 
    void writeFileSecurely(uint64_t element, DESC catalog, uint64_t &skipbytes, WriteEvent &event);
    void startFileWritting(uint64_t chosenElement, DESC catalog);
    void setCryptoMethod(HomomorphicCrypto* crypto_method);
    shared_queue<char*>* getClearDataQueue();
    void join();
    void setdontWrite(bool newvalue);
};

#endif
