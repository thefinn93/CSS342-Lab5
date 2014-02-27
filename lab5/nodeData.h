/* 
 * File:   nodeData.h
 * Author: Nick
 *
 * Created on February 26, 2014, 8:11 PM
 */

#ifndef NODEDATA_H
#define	NODEDATA_H

class nodeData {
public:
    
    /**
     * 
     */
    nodeData();
    
    /**
     * 
     * @param nodeToCopy
     */
    nodeData(const nodeData& nodeToCopy);
    
    /**
     * 
     * @return frequency The frequency of occurrence of the token in the tree.
     */
    int getFrequency();
    
    /**
     * 
     * @return token The token of
     */
    char getToken();
    
    /**
     * 
     * @return True if successful. 
     */
    bool setFrequncy();
    
    /**
     * 
     * @return True if successful.
     */
    bool setToken();
    
private:
    
    int frequency;
    char token[];
    
    nodeData* leftChildPtr;
    nodeData* rightChildPtr;
    
};

#endif	/* NODEDATA_H */

