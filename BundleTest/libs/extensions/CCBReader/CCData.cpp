#include "CCData.h"
#include "CCRange.h"
NS_CC_EXT_BEGIN

CCData::CCData(unsigned char *pBytes, const unsigned long nSize)
{
    m_nSize = nSize;
    m_pBytes = new unsigned char[m_nSize];
    memcpy(m_pBytes, pBytes, m_nSize);
}

CCData::CCData(CCData *pData)
{
    m_nSize = pData->m_nSize;
    m_pBytes = new unsigned char[m_nSize];
    memcpy(m_pBytes, pData->m_pBytes, m_nSize);
}

CCData::~CCData()
{
    CC_SAFE_DELETE_ARRAY(m_pBytes);
}

unsigned char* CCData::getBytes()
{
    return m_pBytes;
}
unsigned long CCData::getSize(){
    return m_nSize;
}

CCData* CCData::subdataWithRange(CCRange range){
    int index=range.location;
    int nLen=range.length;
    CCData* data=NULL;
    unsigned char* pStr = (unsigned char*)malloc(nLen);
    if (pStr != NULL)
    {
        if (nLen > 0)
        {
            memcpy(pStr, m_pBytes+index, nLen);
        }
        data=new CCData(pStr,nLen);
        data->autorelease();
        free(pStr);
    }

    return data;
}
void CCData::getBytes(signed char* buffer ,CCRange range){    
//    for(int i = 0;i < range.length;i++){
//        int shift = (range.length-1-i)  * 8;
        *buffer =(signed char)(m_pBytes[range.location]);
        
//    }
}
NS_CC_EXT_END
