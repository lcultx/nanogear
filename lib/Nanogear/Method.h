/*
 * Nanogear - C++ web development framework
 *
 * This library is based on Restlet (R) <http://www.restlet.org> by Noelios Technologies
 * Copyright (C) 2005-2008 by Noelios Technologies <http://www.noelios.com>
 * Restlet is a registered trademark of Noelios Technologies. All other marks and
 * trademarks are property of their respective owners.
 *
 * Copyright (C) 2008-2009 Lorenzo Villani.
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

#ifndef NANOGEAR_METHOD_H
#define NANOGEAR_METHOD_H

#include <QObject>
#include <QMetaType>

class QString;

namespace Nanogear {

/*!
 * \class Method
 * \brief Encapsulates the requested method
 *
 * Used to determine which method to execute to handle a request. It is usually
 * filled by a concrete implementation of Server.
 */
class Method {
    Q_GADGET
    Q_ENUMS(Type)
public:

    /*!
     * Default constructor. Builds a invalid method.
     */
    Method();

    /*!
     * Build a Method object from its name
     * \param name method's name
     */
    Method(const QString& name);

    /*!
     * This is an overloaded constructor provided for convenience
     * \param name method's name (C-style string)
     */
    Method(const char* name);

    /*!
     * This is an overloaded constructor provided for convenience
     * \param method the code representing a method
     */
    Method(int method);

    ~Method();

    /*!
     * Build this object from the name of the method
     * \param name Method name
     */
    void fromString(const QString& name);

    /*!
     * \return Return the method name as a string
     */
    QString toString() const;

    /*!
     * Build this method from its integer code
     * \param method
     */
    void fromType(int method);

    /*!
     * \return the code associated with this method
     */
    int toType() const;

    bool operator==(const Method& type) const;

    /*!
     * \return If this method is valid or not
     */
    bool isValid() const;

    /*!
     * \return true if this method has a body
     */
    bool hasBody() const;

    enum Type {
        Invalid,
        CONNECT,
        COPY,
        DELETE,
        GET,
        HEAD,
        LOCK,
        MKCOL,
        MOVE,
        OPTIONS,
        POST,
        PROPFIND,
        PROPPATCH,
        PUT,
        TRACE,
        UNLOCK
    };

private:
    struct Private;
    Private* d;
};

}

Q_DECLARE_METATYPE(Nanogear::Method)

#endif // NANOGEAR_METHOD_H
