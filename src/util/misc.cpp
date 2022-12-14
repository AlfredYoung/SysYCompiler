#include "config.hpp"
#include "location.hpp"

// an internal variable
static int __ident = 0;

/* Prints a new line (with indentation).
 *
 * PARAMETERS:
 *   os    - the output stream
 */
void knpc::newLine(std::ostream &os) {
    os << std::endl;
    os.width(__ident);
    os << "";
}

/* Increases the indentation.
 *
 * PARAMETERS:
 *   os    - the output stream
 */
void knpc::incIndent(std::ostream &os) { __ident += 2; }

/* Decreases the indentation.
 *
 * PARAMETERS:
 *   os    - the output stream
 */
void knpc::decIndent(std::ostream &os) { __ident -= 2; }

/* Prints a location record.
 *
 * PARAMETERS:
 *   os    - the output stream
 *   l     - the location record
 * RETURNS:
 *   the output stream
 */
std::ostream &knpc::operator<<(std::ostream &os, Location *l) {
    if (NULL == l)
        os << "(UNKNOWN)";
    else if (l->col < 0) {
        os << "(line ";
        os.width(2);
        os << l->line << ")";
    } else {
        os << "(";
        os.width(2);
        os << l->line << ",";
        os.width(2);
        os << l->col << ")";
    }

    return os;
}
