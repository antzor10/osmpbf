#ifndef OSMPBF_ABSTRACTPRIMITIVEOUTPUTADAPTOR_H
#define OSMPBF_ABSTRACTPRIMITIVEOUTPUTADAPTOR_H

#include <cstdint>
#include <string>

#include "refcountobject.h"

namespace osmpbf {
	class StringTable;

	template<class PrimitiveType>
	class AbstractPrimitiveOutputAdaptor : public RefCountObject {
	public:
		AbstractPrimitiveOutputAdaptor()
			: RefCountObject(), m_StringTable(NULL), m_Data(NULL) {}
		AbstractPrimitiveOutputAdaptor(StringTable * stringTable, PrimitiveType * data)
			: RefCountObject(), m_StringTable(stringTable), m_Data(data) {}

		virtual bool isNULL() const { return !m_StringTable || !m_Data; }

		virtual int64_t id() const;

		virtual void setId(int64_t value);

		virtual int tagsSize() const;

		virtual const std::string & key(int index) const;
		virtual const std::string & value(int index) const;

		virtual void setKey(int index, const std::string & key);
		virtual void setValue(int index, const std::string & value);
		virtual void setValue(const std::string & key, const std::string & value);

		virtual void addTag(const std::string & key, const std::string & value);
		virtual void removeTagLater(int index);

		virtual void clearTags();

	protected:
		StringTable * m_StringTable;
		PrimitiveType * m_Data;
	};
}

class Node;
class Way;

namespace osmpbf {
	template class AbstractPrimitiveOutputAdaptor<Way>;
	template class AbstractPrimitiveOutputAdaptor<Node>;
}
// #include "abstractprimitiveoutputadaptor.tcc"

#endif // OSMPBF_ABSTRACTPRIMITIVEOUTPUTADAPTOR_H