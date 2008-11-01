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

#ifndef NANOGEAR_REST_RESOURCE_REPRESENTATION_HPP
#define NANOGEAR_REST_RESOURCE_REPRESENTATION_HPP

#include <iostream>

#include "variant.hpp"

namespace nanogear {
namespace rest {
namespace resource {

// TODO: Complete implmenetation
class representation : public variant, public std::iostream {
public:
    representation(const data::media_type& t = data::media_type());
    virtual ~representation() { };

    const std::string text() const;
    const bool is_available() const;
    const bool is_transient() const;
    void set_available(bool);
    void set_transient(bool);
private:
    bool m_content_available;
    bool m_content_transient;
};


}
}
}


#endif /* NANOGEAR_REST_RESOURCE_REPRESENTATION_HPP */
