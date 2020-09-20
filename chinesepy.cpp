#include "chinesepy.h"

ChinesePY::ChinesePY()
{

}

QString ChinesePY::ToChineseSpell(QString strText)
{
    if( strText.length() == 0 )
        return strText ;
    QString myStr;
    int index=0;
    for( int i=0;i<strText.length();i++)
    {
        ushort vChar=strText[i].unicode() ;
        if(vChar>19968){
            index = (int)vChar - 19968 ;
            if( index >= 0 && index < strChineseFirstPY.length() ){
                myStr.append( strChineseFirstPY[index]);
            }
        }
        else if( ( vChar >= 'a' && vChar <='z' ) || ( vChar >='A' && vChar <='Z' ) ){
            myStr.append(strText[i].toUpper() );
        }
        else if( ( vChar >='0' && vChar <='9' ) ){
            continue;
        }
    }
    return myStr;
}


