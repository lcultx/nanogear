/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008 Lorenzo Villani.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NANOGEAR_REST_DATA_MESSAGE_HPP
#define NANOGEAR_REST_DATA_MESSAGE_HPP

#include <map>
#include <string>
#include "../resource/representation.hpp"
#include "media_type.hpp"

namespace nanogear {
namespace rest {
namespace data {

class message {
public:
    message() { };
    virtual ~message() { };

    /**
     * return a modifiable list
     */
    std::map<std::string, std::string>& attributes();

    void set_entity(const nanogear::rest::resource::representation&);
    void set_entity(const std::string&, const nanogear::rest::data::media_type&);
private:
    std::map<std::string, std::string> m_attributes;
    nanogear::rest::resource::representation m_entity;
};

}
}
}


#endif /* NANOGEAR_REST_DATA_MESSAGE_HPP */