package org.loose.fis.processor;

import org.loose.fis.document.Document;

import java.util.List;

public interface Processor {
    int process(List<Document> documents);
}