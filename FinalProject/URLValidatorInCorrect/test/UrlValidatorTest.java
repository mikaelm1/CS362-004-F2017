/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.Random;


/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   public void testManualTest()
   {
       //protocol://host.subdomain.topdomain/dir1/dir2/filename.ext
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       ArrayList<String> testurls = new ArrayList<String>();
       System.out.println(urlVal.isValid("http://www.amazon.com"));

       //everything else valid or empty, different schemes
       testurls.add("http://www.google.com");
       testurls.add("http:/www.google.com");
       testurls.add("http:///www.google.com");
       testurls.add("http:\\www.google.com");
       testurls.add("https://www.google.com");
       testurls.add("ftp://www.google.com");
       testurls.add("123://www.google.com");
       testurls.add("foo://www.google.com");
       //everything else valid or empty, different sub-domain
       testurls.add("http://123.google.com");
       testurls.add("http://1.2.3.google.com");
       testurls.add("http://!@#.google.com");
       testurls.add("http://foo.google.com");
       //everything else valid or empty, different domain
       testurls.add("http://www.google.edu");
       testurls.add("http://www.google.co.uk");
       testurls.add("http://www.google.123");
       testurls.add("http://www.google.bar");
       testurls.add("http://www.aaaaaaaaaaaaaaa.com");
       testurls.add("http://www. .com");
       testurls.add("http://www.google. ");
       testurls.add("http://192.128.1.1");
       testurls.add("http://1.1.1.1");
       testurls.add("http://11.11.11.11");
       testurls.add("http://111.111.111.111");
       testurls.add("http://1111.1111.1111.1111");
       testurls.add("http://1.1.1.1.1");
       //everything else valid or empty, different port
       testurls.add("http://www.google.com:0");
       testurls.add("http://www.google.com: ");
       testurls.add("http://www.google.com:80");
       testurls.add("http://www.google.com:423");
       testurls.add("http://www.google.com:32767");
       testurls.add("http://www.google.com:32766");
       testurls.add("http://www.google.com:65535");
       testurls.add("http://www.google.com:65536");
       testurls.add("http://www.google.com:foo");
       testurls.add("https://www.google.com:423");
       testurls.add("https://www.google.com:80");
       testurls.add("https://www.google.com:bar");
       testurls.add("ftp://www.google.com:21");
       testurls.add("ftp://www.google.com:80");
       testurls.add("ftp://www.google.com:bar");
       //everything else valid or empty, different path
       testurls.add("http://www.google.com/foo");
       testurls.add("http://www.google.com/foo/bar");
       testurls.add("http://www.google.com/~foo");
       testurls.add("http://www.google.com//foo");
       testurls.add("http://www.google.com/foo/bar/123/foobar");
       testurls.add("http://www.google.com/foo?bar");
       testurls.add("http://www.google.com/foo$");
       testurls.add("http://www.google.com/ /");
       testurls.add("http://www.google.com\foo");
       for(String url : testurls)
       {
           System.out.println(urlVal.isValid(url) + ": " + url);
       }
   }

    public void testPartitions()
    {
        UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        System.out.println("Testing for http://");
        System.out.println("http://www.google.com is " + urlVal.isValid("http://www.google.com"));
        System.out.println("www.google.com is  " + urlVal.isValid("www.google.com"));

        System.out.println("Testing for port number");
        System.out.println("http://www.google.com:-1 is " + urlVal.isValid("http://www.google.com:-1"));
        System.out.println("http://www.google.com:0 is " + urlVal.isValid("http://www.google.com:0"));
        System.out.println("http://www.google.com:65535 is " + urlVal.isValid("http://www.google.com:65535"));
        System.out.println("http://www.google.com:65536 is " + urlVal.isValid("http://www.google.com:65536"));

        System.out.println("Testing for .com, .net, etc");
        System.out.println("http://www.google is " + urlVal.isValid("http://www.google"));

        System.out.println("Testing for www");
        System.out.println("http://google.com is " + urlVal.isValid("http://google.com"));

        System.out.println("testing for query handling");
        System.out.println("http://www.google.com/search?q=google is " + urlVal.isValid("http://www.google.com/search?q=google"));
        //Testing for ability to handle ?
        System.out.println("http://www.google.com/searchq=google is " + urlVal.isValid("http://www.google.com/searchq=google"));

        System.out.println("Testing IP addresses");
        System.out.println("http://-1.-1.-1.-1 is " + urlVal.isValid("http://-1.-1.-1.-1"));
        System.out.println("http://0.0.0.0 is " + urlVal.isValid("http://0.0.0.0"));
        System.out.println("http://255.255.255.255 is " + urlVal.isValid("http://255.255.255.255"));
        System.out.println("http://256.256.256.256 is " + urlVal.isValid("http://256.256.256.256"));
    }
   
   public void testIsValid()
   {
       UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       Random random = new Random();
       String[] invalidSchemes = getInvalidSchemes();
       String[] validHosts = getValidHosts();
       String[] invalidHosts = getInvalidHosts();
       String[] validSchemes = getValidSchemes();
       // test with invalid schemes
       for (int i = 0; i < 5000; i++) {
           int randomIdxHost = random.nextInt(validHosts.length);
           int randomIdxScheme = random.nextInt(invalidSchemes.length);
           //System.out.println(randomIdx);
           String url = invalidSchemes[randomIdxScheme] + validHosts[randomIdxHost];
           //System.out.println(url);
           assertFalse(urlValidator.isValid(url));
           // test with invalid hosts
           randomIdxScheme = random.nextInt(validSchemes.length);
           randomIdxHost = random.nextInt(invalidHosts.length);
           url = invalidHosts[randomIdxHost] + validSchemes[randomIdxScheme];
           assertFalse(urlValidator.isValid(url));
           // test with valid scheme and valid host
           randomIdxScheme = random.nextInt(validSchemes.length);
           randomIdxHost = random.nextInt(validHosts.length);
           url = validSchemes[randomIdxScheme] + validHosts[randomIdxHost];
           assertTrue(urlValidator.isValid(url));
           // test with invalid paths
           String[] invalidPaths = getInvalidPaths();
           randomIdxScheme = random.nextInt(validSchemes.length);
           int randomIdxPath = random.nextInt(invalidPaths.length);
           url = validSchemes[randomIdxScheme] + invalidPaths[randomIdxPath];
           assertFalse(urlValidator.isValid(url));
           // test with valid paths
           String[] validPaths = getValidPaths();
           randomIdxPath = random.nextInt(validPaths.length);
           url = validSchemes[randomIdxScheme] + validHosts[randomIdxHost] + validPaths[randomIdxPath];
           assertTrue(urlValidator.isValid(url));
           // test with valid ports
           String[] validPorts = getValidPorts();
           int randomPortIdx = random.nextInt(validPorts.length);
           url = validSchemes[randomIdxScheme] + validHosts[randomIdxHost] + validPorts[randomPortIdx];
           assertTrue("Failed with port " + validPorts[randomPortIdx], urlValidator.isValid(url));
       }
   }

    public String[] getInvalidSchemes() {
       String[] schemes = {"boom//", "htp:/", "htps//", "1ttt://"};
       return schemes;
    }

    public String[] getValidSchemes() {
       String[] schemes = {"http://", "ftp://", "https://", "boom://"};
       return schemes;
    }

    public String[] getValidHosts() {
       String[] hosts = {"google.com", "apple.com", "www.osu.org"};
       return hosts;
    }

    public String[] getInvalidHosts() {
       String[] hosts = {"aaa", "bbb", "123", "1.2.3.4"};
       return hosts;
    }

    public String[] getInvalidPaths() {
       String[] paths = {"/test//", "../test", "..."};
       return paths;
    }

    public String[] getValidPaths() {
       String[] paths = {"", "/test/", "/test/foo", "/12"};
       return paths;
    }

    public String[] getValidPorts() {
       String[] ports = {":100", ":1", ":8080", ""};
       return ports;
    }

   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */


}
