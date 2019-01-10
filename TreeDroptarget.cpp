// TreeDropTarget.cpp : implementation file
// For OLE Drag and Drop between tree controls
// Designed and developed by Vinayak Tadas
// vinayakt@aditi.com
// 

#include "stdafx.h"
#include "TreeDroptarget.h"
#include "DragDropTreeCtrl.h"
#include "VideoWin.h"

HWND CTreeDropTarget::m_shWndTreeCtrl = NULL;

/////////////////////////////////////////////////////////////////////////////
// CTreeDropTarget 

/********************************************************************
OnDragEnter()
	Called when the user drags the object in Tree control.
********************************************************************/
DROPEFFECT CTreeDropTarget::OnDragEnter( CWnd* pWnd, COleDataObject* pDataObject, 
	DWORD dwKeyState, CPoint point )
{
	DROPEFFECT dropeffectRet = DROPEFFECT_COPY;
	if ( (dwKeyState & MK_SHIFT) == MK_SHIFT)	//检测是否按了shift键
		dropeffectRet = DROPEFFECT_MOVE;
	return dropeffectRet;
}

/********************************************************************
OnDragOver()
	Called when the user drags the object over Tree control.
********************************************************************/
		
DROPEFFECT CTreeDropTarget::OnDragOver( CWnd* pWnd, COleDataObject* pDataObject, 
	DWORD dwKeyState, CPoint point )
{
	//TRACE("CTreeDropTarget OnDragOver...\n");
	DROPEFFECT dropeffectRet = DROPEFFECT_COPY;
	if ( (dwKeyState & MK_SHIFT) == MK_SHIFT)
		dropeffectRet = DROPEFFECT_MOVE;
	// Expand and highlight the item under the mouse and 
	m_pDestTreeCtrl = (CDragDropTreeCtrl *)pWnd;
	HTREEITEM hTItem = m_pDestTreeCtrl->HitTest(point);
	if ( hTItem != NULL ) 
	{
		m_pDestTreeCtrl->Expand(hTItem, TVE_EXPAND);
		m_pDestTreeCtrl->SelectDropTarget(hTItem);
	}
	return dropeffectRet;
}

/********************************************************************
OnDragLeave()
	Called when the user drags the object out of Tree control.
********************************************************************/
void CTreeDropTarget::OnDragLeave( CWnd* pWnd )
{
	//TRACE("CTreeDropTarget OnDragLeave...\n");
	// Remove Highlighting 
	//m_pDestTreeCtrl = (CDragDropTreeCtrl *)pWnd;
	//m_pDestTreeCtrl->SendMessage(TVM_SELECTITEM, TVGN_DROPHILITE,0);
	
}

/********************************************************************
OnDrop()
	Called when the user drops the object in the  Tree control.
********************************************************************/
BOOL CTreeDropTarget::OnDrop(CWnd* pWnd, COleDataObject* pDataObject,
		DROPEFFECT dropEffect, CPoint point)
{
	m_pSourceTreeCtrl = (CDragDropTreeCtrl *)CWnd::FromHandlePermanent(m_shWndTreeCtrl);
	HTREEITEM hSelectedItem = m_pSourceTreeCtrl->GetSelectedItem();
	CVideoWin* pVideoWin = (CVideoWin*)CWnd::FromHandle(m_hWnd);
	if(pVideoWin == NULL) return FALSE;
	DWORD IData = m_pSourceTreeCtrl->GetItemData(hSelectedItem);
	TREE_NODE_DATA* pNodeData = (TREE_NODE_DATA*)IData;
	if(pNodeData->nType == NODE_TYPE_AREA)
		return FALSE;
	else if(pNodeData->nType == NODE_TYPE_ENCODER)
	{
		hSelectedItem = m_pSourceTreeCtrl->GetChildItem(hSelectedItem);
		IData = m_pSourceTreeCtrl->GetItemData(hSelectedItem);
		pNodeData = (TREE_NODE_DATA*)IData;
		if(pNodeData->nType != NODE_TYPE_CHANNEL)
			return FALSE;
		return pVideoWin->ConnectEncoder(pNodeData->id);
	}
	else if(pNodeData->nType == NODE_TYPE_CHANNEL)
		return pVideoWin->ConnectEncoder(pNodeData->id);
	return FALSE;
}

/********************************************************************
AddItem()
	Recursive function for adding items from selected tree control to
	destination tree control
********************************************************************/
void CTreeDropTarget::AddItem(HTREEITEM hSrcTItem,HTREEITEM hDestTItem )
{
	int nImage;
	int nSelImage;
	while (	(hSrcTItem != NULL) && (hSrcTItem != m_hDestItem)) 
	{
		// Get the item text and Image indexes for source tree control
		CString csItem = m_pSourceTreeCtrl->GetItemText(hSrcTItem);
		GetItemImages(hSrcTItem, nImage, nSelImage);
		
		// Add item to destination tree control
		HTREEITEM hDestChildItem = m_pDestTreeCtrl->AddItem(hDestTItem, csItem, TVI_LAST, nImage, nSelImage, 0);

		m_pDestTreeCtrl->SetItemData(hDestChildItem, m_pDestTreeCtrl->GetItemData(hSrcTItem));	//取数据
		if(m_pDestTreeCtrl->GetCheck(hSrcTItem)) m_pDestTreeCtrl->SetCheck(hDestChildItem);		//取选中
		
		HTREEITEM hSrcChildItem = m_pSourceTreeCtrl->GetChildItem(hSrcTItem);
		
		if(hSrcChildItem != NULL) 
			AddItem(hSrcChildItem, hDestChildItem);
		
		hSrcTItem = m_pSourceTreeCtrl->GetNextSiblingItem(hSrcTItem);
		hDestTItem = m_pDestTreeCtrl->GetParentItem(hDestChildItem);
	}
	
}
/********************************************************************
GetItemImages()
	Gets image indexes associated with a tree item
********************************************************************/
void CTreeDropTarget::GetItemImages(HTREEITEM hSrcTItem, int &nSelItemImage, int &nNonSelItemImage)
{	
	CImageList *pImageList = m_pSourceTreeCtrl->GetImageList(TVSIL_NORMAL);
	//If no image list is associated with the tree control, return
	if (pImageList == NULL )
	{
		nSelItemImage =0;
		nNonSelItemImage = 0;
	}
	else
	{
		// If no image list is associated with Destination tree control
		// Set the image list of source tree control
		if ( m_pDestTreeCtrl->GetImageList(TVSIL_NORMAL) == NULL )
		{
			m_pDestTreeCtrl->SetImageList(pImageList, TVSIL_NORMAL);
		}
		// Get the image indexes
		m_pSourceTreeCtrl->GetItemImage(hSrcTItem, nSelItemImage, nNonSelItemImage);
	}
}
