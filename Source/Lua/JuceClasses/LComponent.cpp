#include "stdafx.h"
#include "LComponent.h"
#include "CtrlrComponents/CtrlrComponent.h"

void LComponent::wrapForLua (lua_State *L)
{
	using namespace luabind;

	module(L)
    [
        class_<DropShadow>("DropShadow")
            .def(constructor<>())
            .def(constructor<Colour, int, Point<int> >())
            .def("drawForImage", &DropShadow::drawForImage)
            .def("drawForPath", &DropShadow::drawForPath)
            .def("drawForRectangle", &DropShadow::drawForRectangle)
        ,
        class_<DropShadower>("DropShadower")
            .def(constructor<const DropShadow &>())
            .def("setOwner", &DropShadower::setOwner)
        ,
		class_<LComponent>("LComponent")
		,
		class_<Component, LComponent>("Component")
			.def(constructor<>())
			.def(constructor<const String &>())
			.def("setName", &Component::setName)
			.def("getComponentID", &Component::getComponentID)
			.def("setComponentID", &Component::setComponentID)
			.def("setVisible", &Component::setVisible)
			.def("isVisible", &Component::isVisible)
			.def("visibilityChanged", &Component::visibilityChanged)
			.def("isShowing", &Component::isShowing)
			.def("addToDesktop", &LComponent::addToDesktop)
			.def("removeFromDesktop", &Component::removeFromDesktop)
			.def("isOnDesktop", &Component::isOnDesktop)
			.def("getPeer", &Component::getPeer)
			.def("userTriedToCloseWindow", &Component::userTriedToCloseWindow)
			.def("minimisationStateChanged", &Component::minimisationStateChanged)
			.def("toFront", &Component::toFront)
			.def("toBack", &Component::toBack)
			.def("toBehind", &Component::toBehind)
			.def("setAlwaysOnTop", &Component::setAlwaysOnTop)
			.def("isAlwaysOnTop", &Component::isAlwaysOnTop)
			.def("getX", &Component::getX)
			.def("getY", &Component::getY)
			.def("getWidth", &Component::getWidth)
			.def("getHeight", &Component::getHeight)
			.def("getRight", &Component::getRight)
			.def("getPosition", &Component::getPosition)
			.def("getBottom", &Component::getBottom)
			.def("getBounds", &Component::getBounds)
			.def("getLocalBounds", &Component::getLocalBounds)
			.def("getBoundsInParent", &Component::getBoundsInParent)
			//.def("getVisibleArea", &Component::getVisibleArea)
			.def("getScreenX", &Component::getScreenX)
			.def("getScreenY", &Component::getScreenY)
			.def("getScreenPosition", &Component::getScreenPosition)
			.def("getScreenBounds", &Component::getScreenBounds)
			.def("getLocalPoint", (Point<int> (Component::*)(const Component *, Point<int>) const) &Component::getLocalPoint)
			.def("getLocalArea", &Component::getLocalArea)
			.def("localPointToGlobal", (Point<int> (Component::*)(Point<int>) const) &Component::localPointToGlobal)
			.def("localAreaToGlobal", &Component::localAreaToGlobal)
			.def("setTopLeftPosition", (void (Component::*)(int,int))&Component::setTopLeftPosition)
			.def("setTopLeftPosition", (void (Component::*)(const Point<int>))&Component::setTopLeftPosition)
			.def("setTopRightPosition", &Component::setTopRightPosition)
			.def("setSize", &Component::setSize)
			.def("setBounds", (void (Component::*)(int,int,int,int))&Component::setBounds)
			.def("setBounds", (void (Component::*)(const Rectangle<int> &))&Component::setBounds)
			.def("setBounds", (void (Component::*)(const RelativeRectangle &))&Component::setBounds)
			.def("setBounds", (void (Component::*)(const String &))&Component::setBounds)
			.def("setBoundsRelative", &Component::setBoundsRelative)
			.def("setBoundsInset", &Component::setBoundsInset)
			.def("setBoundsToFit", &Component::setBoundsToFit)
			.def("setCentrePosition", &Component::setCentrePosition)
			.def("setCentreRelative", &Component::setCentreRelative)
			.def("centreWithSize", &Component::centreWithSize)
			.def("setTransform", &Component::setTransform)
			.def("getTransform", &Component::getTransform)
			.def("isTransformed", &Component::isTransformed)
			.def("proportionOfWidth", &Component::proportionOfWidth)
			.def("proportionOfHeight", &Component::proportionOfHeight)
			.def("getParentWidth", &Component::getParentWidth)
			.def("getParentHeight", &Component::getParentHeight)
			.def("getParentMonitorArea", &Component::getParentMonitorArea)
			.def("getNumChildComponents", &Component::getNumChildComponents)
			.def("getChildComponent", &Component::getChildComponent)
			.def("getIndexOfChildComponent", &Component::getIndexOfChildComponent)
			.def("findChildWithID", &Component::findChildWithID)
			.def("addChildComponent", (void (Component::*)(Component *, int))&Component::addChildComponent)
			.def("addChildComponent", (void (Component::*)(Component &, int))&Component::addChildComponent)
			.def("addAndMakeVisible", (void (Component::*)(Component *, int))&Component::addAndMakeVisible)
			.def("addAndMakeVisible", (void (Component::*)(Component &, int))&Component::addAndMakeVisible)
			.def("addChildAndSetID", &Component::addChildAndSetID)
			.def("removeChildComponent", (void (Component::*)(Component *))&Component::removeChildComponent)
			.def("removeChildComponent", (Component *(Component::*)(int))&Component::removeChildComponent)
			.def("removeAllChildren", &Component::removeAllChildren)
			.def("deleteAllChildren", &Component::deleteAllChildren)
			.def("getParentComponent", &Component::getParentComponent)
			.def("getTopLevelComponent", &Component::getTopLevelComponent)
			.def("isParentOf", &Component::isParentOf)
			.def("parentHierarchyChanged", &Component::parentHierarchyChanged)
			.def("childrenChanged", &Component::childrenChanged)
			.def("hitTest", &Component::hitTest)
			.def("setInterceptsMouseClicks", &Component::setInterceptsMouseClicks)
			.def("getInterceptsMouseClicks", &Component::getInterceptsMouseClicks)
			.def("contains", (bool (Component::*)(const Point<int>))&Component::contains)
			.def("reallyContains", &Component::reallyContains)
			.def("getComponentAt", (Component *(Component::*)(int,int))&Component::getComponentAt)
			.def("getComponentAt", (Component *(Component::*)(const Point<int>))&Component::getComponentAt)
			.def("repaint", (void (Component::*)(void))&Component::repaint)
			.def("repaint", (void (Component::*)(int,int,int,int))&Component::repaint)
			.def("repaint", (void (Component::*)(const Rectangle<int> &))&Component::repaint)
			.def("setBufferedToImage", &Component::setBufferedToImage)
			.def("createComponentSnapshot", &Component::createComponentSnapshot)
			.def("paintEntireComponent", &Component::paintEntireComponent)
			.def("setPaintingIsUnclipped", &Component::setPaintingIsUnclipped)
			.def("setComponentEffect", &Component::setComponentEffect)
			.def("getComponentEffect", &Component::getComponentEffect)
			.def("getLookAndFeel", &Component::getLookAndFeel)
			.def("lookAndFeelChanged", &Component::lookAndFeelChanged)
			.def("sendLookAndFeelChange", &Component::sendLookAndFeelChange)
			.def("setOpaque", &Component::setOpaque)
			.def("isOpaque", &Component::isOpaque)
			.def("setBroughtToFrontOnMouseClick", &Component::setBroughtToFrontOnMouseClick)
			.def("isBroughtToFrontOnMouseClick", &Component::isBroughtToFrontOnMouseClick)
			.def("setWantsKeyboardFocus", &Component::setWantsKeyboardFocus)
			.def("getWantsKeyboardFocus", &Component::getWantsKeyboardFocus)
			.def("setMouseClickGrabsKeyboardFocus", &Component::setMouseClickGrabsKeyboardFocus)
			.def("getMouseClickGrabsKeyboardFocus", &Component::getMouseClickGrabsKeyboardFocus)
			.def("grabKeyboardFocus", &Component::grabKeyboardFocus)
			.def("hasKeyboardFocus", &Component::hasKeyboardFocus)
			.def("moveKeyboardFocusToSibling", &Component::moveKeyboardFocusToSibling)
			.def("createFocusTraverser", &Component::createFocusTraverser)
			.def("getExplicitFocusOrder", &Component::getExplicitFocusOrder)
			.def("setExplicitFocusOrder", &Component::setExplicitFocusOrder)
			.def("setFocusContainer", &Component::setFocusContainer)
			.def("isFocusContainer", &Component::isFocusContainer)
			.def("isEnabled", &Component::isEnabled)
			.def("setEnabled", &Component::setEnabled)
			.def("enablementChanged", &Component::enablementChanged)
			.def("setAlpha", &Component::setAlpha)
			.def("getAlpha", &Component::getAlpha)
			.def("setMouseCursor", &Component::setMouseCursor)
			.def("getMouseCursor", &Component::getMouseCursor)
			.def("updateMouseCursor", &Component::updateMouseCursor)
			.def("paint", &Component::paint)
			.def("paintOverChildren", &Component::paintOverChildren)
			.def("mouseMove", &Component::mouseMove)
			.def("mouseEnter", &Component::mouseEnter)
			.def("mouseExit", &Component::mouseExit)
			.def("mouseDown", &Component::mouseDown)
			.def("mouseDrag", &Component::mouseDrag)
			.def("mouseUp", &Component::mouseUp)
			.def("mouseDoubleClick", &Component::mouseDoubleClick)
			.def("mouseWheelMove", &Component::mouseWheelMove)
			.def("setRepaintsOnMouseActivity", &Component::setRepaintsOnMouseActivity)
			.def("addMouseListener", &Component::addMouseListener)
			.def("removeMouseListener", &Component::removeMouseListener)
			.def("addKeyListener", &Component::addKeyListener)
			.def("removeKeyListener", &Component::removeKeyListener)
			.def("keyPressed", &Component::keyPressed)
			.def("keyStateChanged", &Component::keyStateChanged)
			.def("modifierKeysChanged", &Component::modifierKeysChanged)
			.def("focusGained", &Component::focusGained)
			.def("focusLost", &Component::focusLost)
			.def("focusOfChildComponentChanged", &Component::focusOfChildComponentChanged)
			.def("isMouseOver", &Component::isMouseOver)
			.def("isMouseButtonDown", &Component::isMouseButtonDown)
			.def("isMouseOverOrDragging", &Component::isMouseOverOrDragging)
			.def("getMouseXYRelative", &Component::getMouseXYRelative)
			.def("resized", &Component::resized)
			.def("moved", &Component::moved)
			.def("childBoundsChanged", &Component::childBoundsChanged)
			.def("parentSizeChanged", &Component::parentSizeChanged)
			.def("broughtToFront", &Component::broughtToFront)
			.def("addComponentListener", &Component::addComponentListener)
			.def("removeComponentListener", &Component::removeComponentListener)
			.def("postCommandMessage", &Component::postCommandMessage)
			.def("handleCommandMessage", &Component::handleCommandMessage)
			.def("enterModalState", &Component::enterModalState)
			.def("exitModalState", &Component::exitModalState)
			.def("isCurrentlyModal", &Component::isCurrentlyModal)
			.def("isCurrentlyBlockedByAnotherModalComponent", &Component::isCurrentlyBlockedByAnotherModalComponent)
			.def("canModalEventBeSentToComponent", &Component::canModalEventBeSentToComponent)
			.def("inputAttemptWhenModal", &Component::inputAttemptWhenModal)
			.def("getProperties", (NamedValueSet &(Component::*)() noexcept)&Component::getProperties)
			.def("getProperties", (const NamedValueSet &(Component::*)() const noexcept)&Component::getProperties)
			.def("findColour", &Component::findColour)
			.def("setColour", &Component::setColour)
			.def("removeColour", &Component::removeColour)
			.def("isColourSpecified", &Component::isColourSpecified)
			.def("copyAllExplicitColoursTo", &Component::copyAllExplicitColoursTo)
			.def("colourChanged", &Component::colourChanged)
			.def("getMarkers", &Component::getMarkers)
			.def("getWindowHandle", &Component::getWindowHandle)
			.def("getPositioner", &Component::getPositioner)
			.def("setPositioner", &Component::setPositioner)
			.def("setCachedComponentImage", &Component::setCachedComponentImage)
			.def("getCachedComponentImage", &Component::getCachedComponentImage)
			.scope
			[
				def("getCurrentlyFocusedComponent", &LComponent::getCurrentlyFocusedComponent),
				def("beginDragAutoRepeat", &LComponent::beginDragAutoRepeat),
				def("isMouseButtonDownAnywhere", &LComponent::isMouseButtonDownAnywhere),
				def("getNumCurrentlyModalComponents", &LComponent::getNumCurrentlyModalComponents),
				def("getCurrentlyModalComponent", &LComponent::getCurrentlyModalComponent)
			]
	];
}
