/*
 * Nanogear - C++ web development framework
 * Class to parse URI templates as specified at
 *   http://bitworking.org/projects/URI-Templates/
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

#include <map>
#include <list>
#include <string>
#include <sstream>
#include <iostream>

#include <boost/regex.hpp>


#include "uri_template.hpp"

namespace nanogear {
namespace rest {
namespace util {

std::map<std::string, std::string>& uri_template::var()
{
    return m_vars;
}

void uri_template::set_template_string(const std::string& template_string)
{
    m_template_string = template_string;
}
const std::string& uri_template::template_string() const
{
    return m_template_string;
}

std::string uri_template::expanded()
{
    std::string pass1(m_template_string);
    // Define regexp
    const boost::regex command("\\{-(\\w+)|(\\w+)|(\\w+)\\}");
    const boost::regex variable("\\{(\\w+)\\}");
    const boost::regex variable_defval("\\{(\\w+)=(\\w+)\\}");
    
    // Step 1: Normalization
    // TODO: Normalize the URI and %-encode all the character outside the
    //       reserved space
    // Parsing and substitutions (done via regexp parser)
    // Step 2: variable substitutions
    // Step 2-a: simple variables
    std::string::const_iterator ib, ie;
    ib = m_template_string.begin(); ie = m_template_string.end();

    boost::match_results<std::string::const_iterator> what;
    
    // Step 1: variables
    while(regex_search(ib, ie, what, variable, boost::match_default)) {
        std::string match(what[1].first, what[1].second);
        pass1 = boost::regex_replace(pass1,
            boost::regex(std::string("\\{") + match + std::string("\\}")),
            m_vars[match]);
        ib = what[0].second;
    }

    return pass1; // FIXME: for now...
}

}
}
}