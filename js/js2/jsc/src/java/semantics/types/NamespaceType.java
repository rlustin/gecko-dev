/* 
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is Mountain View Compiler
 * Company.  Portions created by Mountain View Compiler Company are
 * Copyright (C) 1998-2000 Mountain View Compiler Company. All
 * Rights Reserved.
 *
 * Contributor(s):
 * Jeff Dyer <jeff@compilercompany.com>
 */

package com.compilercompany.ecmascript;

/**
 * class NamespaceType
 */

public final class NamespaceType extends ObjectType implements Type {

    boolean debug = false;
  
    public static final TypeValue type = new TypeValue(new NamespaceType());

    public String toString() {
        if( name == null ) {
            return "namespace";
        } else {
            return "namespace("+name+")";
        }
    }

    private String name;

    public NamespaceType(String name) {
	    super("namespace");
        this.name = name;
        NamespaceType.type.addSub(this);
    }

    private NamespaceType() {
	    super("namespace");
        ObjectType.type.addSub(this);
    }

}

/*
 * The end.
 */
