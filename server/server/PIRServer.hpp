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

#ifndef DEF_PIRSERVER
#define DEF_PIRSERVER

#include <string>

#include "PIRSession.hpp"
#include "ServerService.hpp"
#include "../server/DBHandler.hpp"
#include "../server/DBDirectoryProcessor.hpp"
#include "../server/DBGenerator.hpp"

#define DEFAULT_PORT 1234

using namespace boost;

class PIRSession;
struct session_option_t;

class PIRServer 
{
	private:
    boost::asio::io_service ios;
    boost::asio::ip::tcp::acceptor acceptor;
    DBHandler *dbhandler;
    PIRParameters savedPIRParams;
    session_option_t session_option;
    bool drivenMode;
    std::string pirParamsFilePath;
    void handleAccept(boost::shared_ptr<PIRSession> pir_session, const boost::system::error_code& error);
    bool no_pipeline_mode;

	public:
		PIRServer(boost::asio::io_service &ios, unsigned int port, uint64_t split_value, 
        bool usedbgenerator, uint64_t dbgenerator_n, uint64_t dbgenerator_l);
		~PIRServer();
    void serve();
    void readPIRParamsFromFile(const std::string& file_path);
    void processDrivenSession(const std::string& file_path);
    void no_pipeline(bool b);
};

#endif
